#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 4005
#define MK 805
int n, k;
int u[MN][MN];
int rs[MN][MN];
int ps[MN][MN];
int val[MN][MN];

int dp[MN][MK];

/*int solve(int i, int j, int l, int r){ //return the location
    //if(dp[i][j] != -1) return dp[i][j];

    int mn = INF;
    int loc = l;
    FOR(ii, max(j, l), min(i, r)){
        int score = dp[ii-1][j-1] + val[ii][i];
        if(score < mn){
            mn = score;
            loc = ii;
        }
    }

    dp[i][j] = mn;
    return loc;
}*/
void calc(int j, int a, int b, int l, int r){
    if(b < a) return;
    if(a == b){
        int v = INF;
        int loc = l;
        FOR(i, max(j, l), min(i, r)){
            int score = dp[i-1][j-1] + val[i][a];
            if(score < v){
                v = score;
                loc = i;
            }
        }
        dp[a][j] = v;
        
        return;
    }

    //cout << "doing " << j << " " << a << " " << b << " " << l << " " << r << "\n";

    int mid = (a+b)/2;
    int v = INF;
    int loc = l;
    FOR(i, max(j, l), min(i, r)){
        int score = dp[i-1][j-1] + val[i][mid];
        if(score < v){
            v = score;
            loc = i;
        }
    }
    dp[mid][j] = v;

    calc(j, a, mid-1, l, loc);
    calc(j, mid+1, b, loc, r);
}

int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //srand(time(NULL));

    cin >> n >> k;
    getchar();
    FOR(i, 1, n){
        /*if(i == 2000){
            cout << "if this fails time to kms\n";
        }*/
        FOR(j, 1, n){
            //scanf("%d", u[i] + j);
            /*if(i < j){
                u[i][j] = rand()%10;
                u[j][i] = u[i][j];
            }*/
            char c = getchar();
            u[i][j] = c-'0';
            getchar();

            rs[i][j] = rs[i][j-1]+u[i][j];
            ps[i][j] = ps[i-1][j]+rs[i][j];
        }
    }

    /*if(n == 4000){
        cout << "lolme\n";
        return 0;
    }*/

    /*FOR(i, 1, n){
        FOR(j, 1, n){
            cout << u[i][j] << " ";
        }
        cout << "\n";
    }*/

    FOR(i,1,n){
        FOR(j,1,i-1){
            val[i][j] = INF;
        }
        FOR(j,i,n){
            //cout << ps[i][j] << " ";
            val[i][j] = (ps[j][j]-ps[i-1][j]-ps[j][i-1]+ps[i-1][i-1])/2;
            //cout << val[i][j] << " ";
        }
        //cout << "\n";
    }

    FOR(i,1,n){
        dp[i][1] = val[1][i];
    }

    /*if(n == 4000){
        cout << "wtmoo\n";
        return 0;
    }*/
    FOR(j, 2, k){
        calc(j, 1, n, 1, n);

        /*if(n == 4000 && j == 2){
            cout << "well we're still alive\n";
            return 0;
        }*/
    }

    /*FOR(i,1,n){
        FOR(j,1,k){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << dp[n][k] << "\n";

    return 0;
}