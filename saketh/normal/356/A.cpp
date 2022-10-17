#include <iostream>
#include <set>
using namespace std;

const int MAXN = 300005;
const int MAXM = 300005;

int N, M;
int l, r, x;

set<int> alive;
int beat[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M;

    for(int i=0; i<N; i++)
        alive.insert(i+1);
    
    for(int i=0; i<M; i++){
        cin >> l >> r >> x;
        auto it = alive.lower_bound(l);
        while(it != alive.end() && *it <= r){
            if(*it != x){
                beat[*it-1] = x;
                alive.erase(it++);
            }
            else it++;
        }
    }

    for(int i=0; i<N; i++)
        cout << beat[i] << " ";
    cout << endl;
}