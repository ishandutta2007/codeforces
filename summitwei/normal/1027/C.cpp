#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 10000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 10005

int stickNums[MAX_N];
set<int> hasSticks;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;

    for(int i=0; i<T; i++){
        memset(stickNums, 0, sizeof stickNums);
        hasSticks.clear();

        int hasFour = 0;

        int n;
        cin >> n;
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            stickNums[a]++;
            if(stickNums[a] == 2){
                hasSticks.insert(a);
            }

            if(stickNums[a] == 4){
                //cout << a << " " << a << " " << a << " " << a << "\n";
                hasFour = a;
            }
        }

        if(hasFour != 0){
            cout << hasFour << " " << hasFour << " " << hasFour << " " << hasFour << "\n";
            continue;
        }

        //double minAns = INF;
        double rat = INF;
        ll side1, side2;
        set<int>::iterator u = hasSticks.begin();
        u++;
        for(u; u != hasSticks.end(); ++u){
            int j = *u;
            u--;
            int prevNum = *u;
            u++;
            /*if(stickNums[j] < 2) continue;
            if(stickNums[j] >= 4){
                minAns = 16;
                side1 = j;
                side2 = j;
                break;
            }
            
            double thisOne = 4*(prevNum+j)*(prevNum+j)/(prevNum*j);
            if(thisOne < minAns){
                minAns = thisOne;
                side1 = prevNum;
                side2 = j;
            }*/

            if(j/(prevNum+0.0) < rat){
                side1 = prevNum;
                side2 = j;
                rat = j/(prevNum+0.0);
            }

            prevNum = j;
        }

        cout << side1 << " " << side1 << " " << side2 << " " << side2 << "\n";
    }
    
    return 0;
}