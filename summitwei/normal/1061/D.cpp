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
#define MAX_N 100005
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

pll shows[MAX_N];
ll n, x, y;

priority_queue<ll, vector<ll>, greater<ll> > pq;
priority_queue<ll> pq2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x >> y;

    F0R(i, n){
        cin >> shows[i].f >> shows[i].s;
    }

    sort(shows, shows+n);

    ll totCost = 0;
    F0R(i, n){
        /*while(!pq.empty() && (shows[i].f-pq.top()) * y > x){
            pq.pop();
            //cout << "popped\n";
        }*/

        while(!pq.empty() && shows[i].f > pq.top()){
            pq2.push(pq.top());
            pq.pop();
        }

        if(pq2.empty() || (shows[i].f-pq2.top()) * y > x){
            while(!pq2.empty()) pq2.pop(); //these are all useless
            totCost = (totCost + x + ((shows[i].s - shows[i].f) * y) % MOD) % MOD;
            pq.push(shows[i].s);
        } else{
            totCost = (totCost + (shows[i].s - pq2.top()) * y) % MOD;
            pq2.pop();
            pq.push(shows[i].s);
        }

        /*if(pq.empty() || pq.top() >= shows[i].f){
            totCost = (totCost + x + ((shows[i].s-shows[i].f)*y) % MOD) % MOD;
            pq.push(shows[i].s);
        } else{
            totCost = (totCost + (shows[i].s - pq.top()) * y) % MOD;
            pq.pop();
            pq.push(shows[i].s);
        }*/
        //cout << "cost is " << totCost << "\n";
    }

    cout << totCost << "\n";
    
    return 0;
}