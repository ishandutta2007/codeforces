#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MAXN = 100005;

int p[MAXN];
set<int> ms;
int N, v[MAXN], l[MAXN];
vector<pair<int, int> > mv;

int main(){
    for(int q=2; q<MAXN; q++)
        if(p[q]) continue;
        else{
            ms.insert(q-1);
            for(int r=q; r<MAXN; r+=q)
                p[r] = q;
        }

    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v[i];
        l[--v[i]] = i;
    }

    for(int i=0; i<N; i++){
        while(l[i] > i){
            int ln = *(--ms.upper_bound(l[i]-i));
            mv.emplace_back(l[i]-ln+1, l[i]+1);
            swap(v[l[i]], v[l[i]-ln]);
            swap(l[i], l[v[l[i]]]);
        }
    }

    cout << mv.size() << "\n";
    for(int i=0; i<mv.size(); i++)
        cout << mv[i].first << " " << mv[i].second << "\n";
    cout.flush();
    return 0;
}