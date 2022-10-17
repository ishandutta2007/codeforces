#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int inp[200005];
vector<pair<int, int> > pegs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> inp[i];
        pegs.emplace_back(inp[i], i);
    }

    pegs.emplace_back(-0x7f7f7f7f, -1);
    sort(pegs.begin(), pegs.end());

    int p, l;
    for(int i=0; i<M; i++){
        cin >> p >> l;
        p--;
        
        while(true){
            auto it1 = --upper_bound(pegs.begin(), pegs.end(), make_pair(inp[p]+l, 0x7f7f7f7f));
            l -= it1->first - inp[p];
            auto it2 = lower_bound(pegs.begin(), pegs.end(), make_pair(it1->first - l, -1)); 
            l -= it1->first - it2->first;

            if(it2->second == p){
                int loop = it1->first - inp[p];
                if(loop == 0){
                    cout << p+1 << "\n";
                    break;
                }
                else l %= (2 * loop);
            }
            else{
                p = it2->second;
            }
        }
    }
}