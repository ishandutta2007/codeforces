#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<int,int,int>
using Graph = vector<vector<int>>;

const ll mod = 1000000007;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N,M; cin >> N >> M;
    Graph G(N+1),rev(N+1);
    ll cnt[N+1];
    rep(i,N+1) cnt[i] = 0;
    rep(i,N){
        ll c; cin>> c;
        rep(j,c){
            ll d; cin >> d;
            G[d].push_back(i+1); cnt[i+1]++;
            rev[i+1].push_back(d);
        }
    }
    ll f; cin >> f;
    bool rf[N+1],rt[N+1];
    rep(i,N+1){
        rf[i] = false; rt[i] = false;
    }
    queue<int> go; go.push(f); rt[f] = true; rf[f] = true;
    //BFS ()
    while(!go.empty()){
        int s = go.front(); go.pop();
        for(int x:G[s]){
            if(rt[x]) continue;
            rt[x] = true;
            go.push(x);
        }
    }
    go.push(f);
    while(!go.empty()){
        int s = go.front(); go.pop();
        for(int x:rev[s]){
            if(rf[x]) continue;
            rf[x] = true;
            go.push(x);
        }
    }

    bool dp[N+1][3];
    int from[N+1][2];
    bool vistemp[N+1],vistrue[N+1];
    rep(i,N+1){
        vistemp[i] = false; vistrue[i] = false; 
        rep(j,2){
            dp[i][j] = false;
            from[i][j] = -1;
        }
        dp[i][2] = true;
    }
    
    //BFS ()
    queue<int> tmp; 
    rep(i,N){
        if(cnt[i+1]==0){
            go.push(i+1); dp[i+1][1] = true; //0:win 1:Lose 2:draw
            vistrue[i+1] = true;
        }
    }
    ll stemp;

    while(!go.empty()){
        int s = go.front(); go.pop();
        //cout << s << endl;
        for(int x:G[s]){
            if(dp[s][0]){
                dp[x][1] = true;
                if(from[x][1]<=0) from[x][1] = s;
            }
            if(dp[s][1]){
                dp[x][0] = true;
                if(from[x][0]<=0) from[x][0] = s;
            }
            cnt[x]--;
            if(cnt[x]==0){
                vistrue[x] = true; go.push(x);
            }
            else{
                if(tmp.empty()&&rf[x]&&rt[x]&&G[x].size()!=0){
                    vistemp[x] = true; tmp.push(x); stemp = x;
                }
            }
        }
    }

    if(vistrue[f]){
        if(dp[f][0]){
        cout << "Win" << endl;
        ll nw = f; int sc = 0;
        while(nw>0){
            cout << nw << " ";
            nw = from[nw][sc]; sc = 1-sc;
        }
            cout << endl;
        }
        else cout << "Lose" << endl;
        return 0;
    }

    //BFS ()
    ll dist[N+1][2]; // ll par[N+1];
    ll from2[N+1][2];
    rep(i,N+1){
        rep(j,2){
            dist[i][j] = 2000000000; from2[i][j] = -1;
        }
    }
    dist[f][0] = 0; go.push(2*f);
    while(!go.empty()){
        int s = go.front(); go.pop();
        int pt = s%2; s /= 2;
        for(int x:rev[s]){
            if(dist[x][1-pt]<=dist[s][pt]+1) continue;
            dist[x][1-pt] = dist[s][pt]+ 1;
            //from2[x][1-pt] = s;
            //par[x] = s;
            go.push(2*x+(1-pt));
        }
    }
    ll key = -1,ks = 0;
    rep(i,N){
        if(dp[i+1][0]&&dist[i+1][0]<2e8){
            key = i+1; break;
        }
        if(dp[i+1][1]&&dist[i+1][1]<2e8){
            key = i+1; ks = 1; break;
        }
    }

    if(key>0){
        cout << "Win" << endl;
        ll nw = f; int sc = 0;
        rep(i,N+1){
            rep(j,2){
                dist[i][j] = 2000000000; from2[i][j] = -1;
            }
        }
        dist[key][ks] = 0; go.push(2*key+ks);
        while(!go.empty()){
            int s = go.front(); go.pop();
            int pt = s%2; s /= 2;
            for(int x:G[s]){
                if(dist[x][1-pt]<=dist[s][pt]+1) continue;
                dist[x][1-pt] = dist[s][pt]+ 1;
                from2[x][1-pt] = s;
                //par[x] = s;
                go.push(2*x+(1-pt));
            }
        }
        while(nw!=key||sc!=ks){
            cout << nw << " ";
            //cout << nw << " " << sc << " " << from2[nw][sc] << endl;
            nw = from2[nw][sc]; sc = 1-sc;
        }
        while(nw>0){
            cout << nw << " ";
            nw = from[nw][sc]; sc = 1-sc;
        }
        cout << endl;
    }
    else{
        cout << "Draw" << endl;
    }
    //cout << ans << endl;
}