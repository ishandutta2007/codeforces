#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 1000000
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N;
int q;

ll s[MAX_N];
int len[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin >> q;
    
    ll ts = 0;
    
    F0R(i, N){
        cin >> s[i];
        ts += s[i];
    }
    
    F0R(_, q){
        ll b;
        cin >> b;
        if(ts <= b){
            cout << 1 << "\n";
            continue;
        }
        
        int minLen = INF;
        int minInd = 0;
        
        int r = 0;
        ll sum = s[0];
        F0R(i, N){
            while(sum+s[(r+1)%N] <= b){
                r = (r+1)%N;
                sum += s[r];
            }
            len[i] = (N+r-i)%N;
            sum -= s[i];
            //cout << len[i] << " ";
            
            if(i >= 1 && len[i] != len[i-1]-1 && len[i] < minLen){
                minLen = len[i];
                minInd = i;
            }
        }
        //cout << " minInd/Len: ";
        
        if(len[0] != len[N-1]-1 && len[0] < minLen){
            minLen = len[0];
            minInd = 0;
        }
        
        //cout << minInd << " " << minLen << "\n";
        
        int minAns = INF;
        FOR(i, minInd, minInd+minLen){
            int g = 0;
            int cur = i;
            int trav = 0;
            do{
                g++;
                trav += len[cur]+1;
                cur = (cur+len[cur]+1) % N;
            } while(trav < N);
            
            minAns = min(minAns, g);
        }
        
        cout << minAns << "\n";
    }
    
    return 0;
}