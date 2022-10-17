#include <iostream>
#include <set>
using namespace std;

const int MAXN = 100005;
const int MAXM = 10;

int N, M, K;
set<pair<int, int> > det[MAXM];
int rob[MAXN][MAXM];

int best = 0;
int shots[MAXM];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> rob[i][j];

    int i=0;

    for(int j=0; j<N; j++){
        for(int k=0; k<M; k++)
            det[k].insert(make_pair(rob[j][k], j));

        while(det[0].size() > 0){
            int make = 0;
            for(int k=0; k<M; k++)
                make += det[k].rbegin()->first;

            if(make > K){
                for(int k=0; k<M; k++)
                    det[k].erase(make_pair(rob[i][k], i));
                i++;
            }
            else{
                if(j-i+1 > best){
                    best = j-i+1;
                    for(int k=0; k<M; k++)
                        shots[k] = det[k].rbegin()->first;
                }
                break;
            }
        }
    }

    for(int i=0; i<M; i++)
        cout << shots[i] << " ";
    cout << endl;
}