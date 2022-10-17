#include <cstdio>
#include <vector>
using namespace std;

const int S = 1000000;

int N, h;
bool u[S + 5];
bool d[S + 5];
int x[S/2 + 5];
vector<pair<int, int> > f;
vector<int> y;

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &x[i]);
        u[x[i]] = true;
    }

    for(int i=1; i<=S; i++){
        int yv = S - i;
        int pc = S - 1 - yv;
        int pv = S - pc;

        if(u[i] || u[pv]) continue;

        f.push_back(make_pair(i, pv));
    }

    for(int i=1; i<=S; i++){
        if(!u[i]) continue;
        if(d[i]) continue;

        int pv = S+1-i;
        if(!u[pv]) y.push_back(pv);
        else{
            d[pv] = true;
            pair<int, int> m = f[h++];
            y.push_back(m.first);
            y.push_back(m.second);
        }
    }

    printf("%ld\n", y.size());
    for(int x : y) printf("%d ", x);
    printf("\n");
    return 0;
}