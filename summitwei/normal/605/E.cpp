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
#define MAX_N 1005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

int N;
int mat[MAX_N][MAX_N];

double prodSum[MAX_N];
double prob[MAX_N]; //prob you don't have anything open

double xp[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(xp, -1, sizeof xp);

    cin >> N;
    F0R(i, N){
        F0R(j, N){
            cin >> mat[i][j];
        }
        prob[i] = 1;
    }

    if(N == 1){
        cout << "0\n";
        return 0;
    }

    xp[N-1] = 0;
    F0R(i, N-1){
        //prodSum[i] += (mat[i][N-1] * prob[i]);
        prob[i] *= 1-(mat[i][N-1]/100.0);
    }
    
    F0R(_, N-1){
        double best = INF;
        int ind = 0;

        F0R(i, N){
            if(xp[i] > -0.5) continue;
            if(prob[i] > 1-EPSILON) continue;

            double curr = (prodSum[i]+1)/(1-prob[i]);
            //cout << "curr for " << i << " is " << curr << "\nprob is " << prob[i] << " prodsum " << prodSum[i] << "\n";
            if(curr < best){
                best = curr;
                ind = i;
            }
        }
        
        if(ind == 0){
            cout << setprecision(8) << best << "\n";
            return 0;
        }

        xp[ind] = best;

        F0R(i, N){
            if(xp[i] > -0.5) continue;

            prodSum[i] += ((mat[i][ind]/100.0)*prob[i]*best);
            prob[i] *= 1-(mat[i][ind]/100.0);
        }
    }


    return 0;
}