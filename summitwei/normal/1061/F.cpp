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
#define MAX_N 1505
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int n, k;

bool query(int a, int b, int c){
    cout << "? " << a << " " << b << " " << c << "\n";
    cout.flush();

    string resp;
    cin >> resp;
    
    if(resp == "Yes") return true;
    else return false;
}

set<int> works;
int btwn(int a, int b){
    works.clear();

    int cnt = 0;

    FOR(i, 1, n){
        if(i == a || i == b) continue;
        if(query(a, i, b)){
            cnt++;
            works.insert(i);
        }
    }

    return cnt;
}

bool checked[MAX_N][MAX_N];

int btwn2(int a, int b){
    int cnt = 0;
    for(auto u : works){
        if(u == b) continue;
        if(query(a, u, b)){
            cnt++;
        }
    }

    return cnt;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    srand(time(NULL));

    cin >> n >> k;
    int depth = round(((double)log(n*(k-1)+1))/((double)log(k)) - 1);

    //cout << depth << "\n";

    int a, b;
    F0R(i, 55){
        do{
            a = rand() % n + 1;
            b = rand() % n + 1;

            //cout << "randed " << a << " " << b << "\n";

            if(a > b) swap(a, b);
        } while(a == b || checked[a][b]);

        checked[a][b] = true;
        int dist = btwn(a, b);
        if(dist == depth*2-1){
            break;
        }
    }

    for(auto u : works){
        if(btwn2(a, u) == depth-1){
            cout << "! " << u << "\n";
            return 0;
        }
    }
    
    return 0;
}