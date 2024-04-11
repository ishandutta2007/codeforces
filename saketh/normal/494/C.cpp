#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MAXQ = 5005;
typedef long long ll;

struct range{
    int x, y;
    double ch;
    bool operator<(const range &o) const{
        if(this->x == o.x) return this->y > o.y;
        return this->x < o.x;
    }
};

int N, Q;
range give[MAXQ];
ll init[MAXN], max_elt[MAXQ];
bool cov[MAXN], pro[MAXQ];
double gle[MAXQ][MAXQ];

int main(){
    cin >> N >> Q; Q++;
    for(int i=0; i<N; i++)
        cin >> init[i];

    give[0].x = 0, give[0].y = N-1; give[0].ch = 0;
    for(int i=1; i<Q; i++){
        cin >> give[i].x >> give[i].y >> give[i].ch;
        give[i].x--;
        give[i].y--;
    }
    sort(give, give+Q);

    for(int i=Q-1; i>=0; i--){
        max_elt[i] = -2*Q;
        ll max_unc = -2*Q;
        for(int e=give[i].x; e<=give[i].y; e++){
            if(!cov[e]){ cov[e] = true; max_unc = max(max_unc, init[e]); }
            max_elt[i] = max(max_elt[i], init[e]);
        }

        vector<int> child;
        for(int j=i+1; j<Q; j++)
            if(!pro[j] && give[j].x <= give[i].y){
                pro[j] = true;
                child.push_back(j);
            }

        for(int k=0; k<=Q; k++){
            double cury = give[i].ch, curn = 1 - cury;
            if(k == 0 && max_unc == max_elt[i]) cury = 0;
            for(int j=0; j<child.size(); j++){
                int l = k + max_elt[i] - max_elt[child[j]];
                cury *= (l?((l-1)<=Q?gle[child[j]][l-1]:1):0);
                curn *= (l<=Q?gle[child[j]][l]:1);
            }
            gle[i][k] = cury + curn;
        }
    }

    double ans = 0;
    for(int k=0; k<=Q; k++){
        double prob = gle[0][k] - (k?gle[0][k-1]:0);
        ans += (max_elt[0] + k) * prob;
    }
    cout.precision(20);
    cout << ans << endl;
    return 0;
}