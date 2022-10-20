#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;
#define double long double

const ll mod = 998244353;

vector<vector<ll>> anc(2000+1);
//dfs
//s: i:dfs t:
vector<int> vis; int t;
vector<int> depth;
//L
int L;
void dfs(Graph &G, int s,int i){
    anc[s].push_back(i);
    t++;
    for(int nx:G[s]){
        if(t>=L) break;
        if(vis[nx]==i) continue;
        depth[nx] = depth[s] + 1;
        vis[nx] = i;
        dfs(G,nx,i);
    }
    t--;
}
    

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N; cin >> N;
    if(N==1){
        cout << "? " << 1 << " " << N << endl;
        string S; cin >> S;
        cout << "! " << S << endl; return 0;
    }
    cout << "? " << 1 << " " << N << endl;
    vector<vector<string>> ss(N+1);
    rep(i,N*(N+1)/2){
        string s; cin >> s;
        ss[s.size()].push_back(s);
    }
    ll cnt[26],cb[26];
    rep(i,26){
        cnt[i] = 0; cb[i] = 0;
    }
    for(string t:ss[1]){
        char c = t[0];
        cb[(c-'a')]++;
    }
    vector<multiset<char>> cand((N+1)/2+1);
    rep(i,(N+1)/2){
        rep(j,26) cnt[j] = 0;
        for(string t:ss[i+2]){
            rep(j,i+2){
                char c = t[j];
                cnt[(c-'a')]++;
            }
        }
        rep(j,i){
            for(char c:cand[j+1]){
                cnt[(c-'a')] += (i+2)-(j+1);
            }
        }
        rep(j,26){
            rep(k,cb[j]*(i+2)-cnt[j]){
                cand[i+1].insert((char)('a'+j));
            }
        }
    }

    cout << "? " << 2 << " " << N << endl;
    vector<vector<string>> ss2(N+1);
    rep(i,N*(N-1)/2){
        string s; cin >> s;
        ss2[s.size()].push_back(s);
    }
    ll cnt2[26],cb2[26];
    rep(i,26){
        cnt2[i] = 0; cb2[i] = 0;
    }
    for(string t:ss2[1]){
        char c = t[0];
        cb2[(c-'a')]++;
    }
    vector<multiset<char>> cand2((N)/2+1);
    rep(i,(N)/2){
        rep(j,26) cnt2[j] = 0;
        for(string t:ss2[i+2]){
            rep(j,i+2){
                char c = t[j];
                cnt2[(c-'a')]++;
            }
        }
        rep(j,i){
            for(char c:cand2[j+1]){
                cnt2[(c-'a')] += (i+2)-(j+1);
            }
        }
        rep(j,26){
            rep(k,cb2[j]*(i+2)-cnt2[j]){
                cand2[i+1].insert((char)('a'+j));
            }
        }
    }

    for(char c:cand[1]){
        //cout << c << endl;
    }

    string ans;
    rep(i,N) ans += 'a';
    rep(i,26){
        if(cb[i]!=cb2[i]){
            ans[0] = (char)('a'+i);
            cand[1].erase(cand[1].find(ans[0]));
        }
    }
    rep(i,N-1){
        if(i%2==0){
            auto itr = cand[i/2+1].begin();
            char c = *itr;
            ans[N-1-i/2] = c;
            if(i==N-2) continue;
            cand2[i/2+1].erase(cand2[i/2+1].find(c));
        }
        else{
            auto itr = cand2[i/2+1].begin();
            char c = *itr;
            ans[1+i/2] = c;
            if(i==N-2) continue;
            cand[i/2+2].erase(cand[i/2+2].find(c));
        }
    }
    cout << "! " << ans << endl;
}