#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 505

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int works = true;

        int n;
        string str;
        cin >> n >> str;
        for(int i=0; i<=n/2; i++){
            int front = str[i];
            int back = str[n-1-i];
            if(abs(front-back) != 2 && abs(front-back) != 0){
                works = false;
                break;
            }
        }
        
        if(works){
            cout << "YES\n";
        } else{
            cout << "NO\n";
        }
    }
    
    return 0;
}