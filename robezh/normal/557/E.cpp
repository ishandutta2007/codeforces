#include <bits/stdc++.h>
using namespace std;

const int N = 5050, M = N * N / 2;

struct node{
    int cnt[3];
    int nxt[2];
    node(){
        fill(cnt, cnt+3, 0);
        fill(nxt, nxt+2, -1);
    }
} nds[M];

int cnt = 0;
string s;
int k;
bool dp[N][N];
int psum[N][N];


int main(){
    getline(cin, s);
    cin >> k;
    for(int len = 0; len < s.length(); len++){
        for(int st = 0; st + len < s.length(); st++){
            if(len == 0) dp[st][st] = true;
            else if(len >= 1 && len <= 3) dp[st][st+len] = (s[st] == s[st+len]);
            else dp[st][st+len] = (s[st] == s[st+len]) && dp[st+2][st+len-2];
        }
    }
    nds[cnt++] = node();

    for(int st = 0; st < s.length(); st++){
        int cur = 0;
        int las = 0;
        int sum = 0;

        for(int ed = st; ed < s.length(); ed++) sum += dp[st][ed];

        for(int ed = st; ed < s.length(); ed++){
            int x = s[ed] - 'a';
            nds[cur].cnt[x] += sum;
            if(nds[cur].nxt[x] == -1) nds[cur].nxt[x] = cnt++;
            cur = nds[cur].nxt[x];

            las = dp[st][ed];
            nds[cur].cnt[2] += las;
            sum -= las;
        }
    }

    string res;
    int cur = 0;
    while(true){
        if(nds[cur].cnt[2] >= k){
            break;
        }
        else if(nds[cur].cnt[0] + nds[cur].cnt[2] >= k){
            res.push_back('a');
            k -= nds[cur].cnt[2];
            cur = nds[cur].nxt[0];
        }
        else{
            res.push_back('b');
            k -= nds[cur].cnt[0] + nds[cur].cnt[2];
            cur = nds[cur].nxt[1];
        }
    }
    cout << res << endl;
}