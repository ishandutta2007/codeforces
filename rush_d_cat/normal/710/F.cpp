#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 300000+10;
const int K = 550;
int m, op; char s[N];
struct Trie {
    int ch[N][30], cnt[N], size;
    void insert(char * s, int val) {
        int now = 0;
        for (int i = 0; s[i]; i ++) {
            int c = s[i]-'a';
            if (ch[now][c] == 0) {
                ch[now][c] = ++ size;
            }
            now = ch[now][c];
        }
        cnt[now] += val;
    }
    int query(char * s) {
        int now = 0, ans = 0;
        for (int i = 0; s[i]; i ++) {
            int c = s[i]-'a';
            if (ch[now][c] == 0)
                break;
            now = ch[now][c];
            ans += cnt[now];
        }
        return ans;
    }
} trie;
struct Kmp {
    int nex[N];
    void buildNext(string s) {
        int len = s.length();
        for(int i=0;i<len;i++) nex[i]=0;
        int i=0,j=-1; nex[0]=-1;
        while (i<len) {
            if (j==-1 || s[i]==s[j]) {
                ++ i, ++ j;
                nex[i] = j;
            } else {
                j = nex[j];
            }
        }
    }
    int query(string t, char * s) { // st
        buildNext(t);
        int sum=0,j=0,len=t.length();
        for(int i=0;s[i];i++) {
            while(j>0 && t[j]!=s[i]) {
                j=nex[j];
            }
            if (t[j]==s[i]) j++;
            if (j==len) {
                sum ++, j = nex[j];
            }
        }
        return sum;
    }
} kmp;

string Bstr[N];
int Btype[N], cnt=0;

int main() {
    scanf("%d", &m);
    while (m --) {
        scanf("%d %s", &op, s);
        int len = strlen(s);
        if (op==1) {
            if (len <= K) {
                trie.insert(s, 1);
            } else {
                Btype[++cnt] = 1;
                Bstr[cnt] = string(s);
            }
        } else if (op == 2) {
            if (len <= K) {
                trie.insert(s, -1);
            } else {
                Btype[++cnt] = -1;
                Bstr[cnt] = string(s);
            }            
        } else {
            long long ans = 0;
            for(int i=0;s[i];i++) {
                ans += trie.query(s+i);
            }
            for (int i=1;i<=cnt;i++) {
                if (Bstr[i].length() > len) continue;
                ans += Btype[i] * kmp.query(Bstr[i], s);
            }
            printf("%lld\n", ans);
            fflush(stdout);
        }
    }
}