#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

namespace SA {
    const int N = 400000 + 10;
    char s[N];int n;
    int height[N],rk[N],sa[N],cc[N],t1[N],t2[N];
    bool cmp(int *y,int a,int b,int k){
        int a1=y[a],a2=a+k>=n?-1:y[a+k];
        int b1=y[b],b2=b+k>=n?-1:y[b+k];
        return a1==b1&&a2==b2;
    }
    void buildSA(int m) {
        int *x=t1,*y=t2;
        for(int i=0;i<m;i++) cc[i]=0;
        for(int i=0;i<n;i++) cc[x[i]=s[i]]++;
        for(int i=1;i<m;i++) cc[i]+=cc[i-1];
        for(int i=n-1;i>=0;i--) sa[--cc[x[i]]]=i;
        for(int k=1;k<=n;k<<=1) {
            int p=0;
            for(int i=n-k;i<n;i++) y[p++]=i;
            for(int i=0;i<n;i++)
                if(sa[i]>=k) y[p++]=sa[i]-k;

            for(int i=0;i<m;i++) cc[i]=0;
            for(int i=0;i<n;i++) cc[x[y[i]]] ++;
            for(int i=1;i<m;i++) cc[i]+=cc[i-1];
            for(int i=n-1;i>=0;i--) sa[--cc[x[y[i]]]]=y[i];
            swap(x,y);
            m=1,x[sa[0]]=0;
            for(int i=1;i<n;i++) {
                x[sa[i]]=cmp(y,sa[i-1],sa[i],k)?m-1:m++;
            }
            if(m>=n) break;
        }
    }
    void buildH(){
        for(int i=0;i<n;i++)
            rk[sa[i]]=i;
        int k=0; height[0]=0;
        for(int i=0;i<n;i++) {
            if(!rk[i]) continue;
            if(k) k--;
            int j=sa[rk[i]-1];
            while(s[i+k]==s[j+k]) k++;
            height[rk[i]]=k;
        }
    }
    int LG[1<<20],st[N][20];
    void RmqInit() {
        for(int i=0;i<n;i++)
            st[i][0]=height[i];

        for(int i=1;i<20;i++)
        for(int j=0;j<n;j++)
            if(j+(1<<i)<=n)
                st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
    }

    int LCP(int x, int y) { // suffix(x) & suffix(y)
        if (x==y) return n-x;
        int l = min(rk[x], rk[y]) + 1;
        int r = max(rk[x], rk[y]); 
        int k = LG[r-l+1];
        return min(st[l][k], st[r-(1<<k)+1][k]);
    }
    void init(int nn, char ss[]) {
        //memset(st,0,sizeof(st));
        for(int i=0;i<=nn+2;i++) {
            height[i] = rk[i] = sa[i] = 0;
        }
        n = nn;
        for (int i = 0; i <= n; i ++) s[i] = ss[i];
        buildSA(1000); buildH(); RmqInit();
    /*
        for (int i = 0; i < n; i ++) {
            printf("%s %d\n", s + sa[i], height[i]);
        }
        printf("\n");
    */
    }
    bool can_delete(int l1, int r1, int l2, int r2) {
        int pre = LCP(l1, l2);
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        return pre >= min(len1, len2);
    }
    bool my_cmp(int l1, int r1, int l2, int r2) {
        int pre = LCP(l1, l2);
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        if (pre >= min(len1, len2)) {
            return len1 < len2;
        }
        return s[l1 + pre] < s[l2 + pre];
    }
    bool check2(vector< pair<int,int> > vec1,vector< pair<int,int> > vec2) {
        /*
        printf("vec1: "); for (auto p: vec1) printf("[%d,%d] ", p.first,p.second); printf("\n");
        printf("vec2: "); for (auto p: vec2) printf("[%d,%d] ", p.first,p.second); printf("\n");
        */
        if (min(vec1.size(), vec2.size()) == 0) 
            return vec1.size() < vec2.size();

        int l1 = vec1[0].first, r1 = vec1[0].second;
        int l2 = vec2[0].first, r2 = vec2[0].second;
        if (can_delete(l1, r1, l2, r2)) {
            vector< pair<int,int> > nvec1, nvec2;
            if (r1 - l1 < r2 - l2) {
                for (int i = 1; i < vec1.size(); i ++) 
                    nvec1.push_back(vec1[i]);
                nvec2 = vec2;
                nvec2[0].first += vec1[0].second - vec1[0].first + 1;
            } else if (r1 - l1 > r2 - l2) {
                for (int i = 1; i < vec2.size(); i ++) 
                    nvec2.push_back(vec2[i]);
                nvec1 = vec1;
                nvec1[0].first += vec2[0].second - vec2[0].first + 1;
            } else {
                for (int i = 1; i < vec1.size(); i ++) 
                    nvec1.push_back(vec1[i]);
                for (int i = 1; i < vec2.size(); i ++) 
                    nvec2.push_back(vec2[i]);
            }
            if (nvec1.size() == 0 && nvec2.size() == 0) {
                return vec1[0].second < vec2[0].second;
            }
            return check2(nvec1, nvec2);
        }
        return my_cmp(l1, r1, l2, r2);
    }
    bool check1(int l1, int r1, int m1, int l2, int r2, int m2) {
        if (l1 > r1 && l2 > r2) return r1 < r2;
        if (l1 > r1) return 1;
        if (l2 > r2) return 0;

        vector< pair<int,int> > vec1, vec2;
        if (l1 <= m1 && m1 <= r1) {
            if (l1 <= m1 - 1) vec1.push_back(make_pair(l1, m1 - 1));
            if (m1 + 1 <= r1) vec1.push_back(make_pair(m1 + 1, r1));
        } else {
            vec1.push_back(make_pair(l1, r1));
        }

        if (l2 <= m2 && m2 <= r2) {
            if (l2 <= m2 - 1) vec2.push_back(make_pair(l2, m2 - 1));
            if (m2 + 1 <= r2) vec2.push_back(make_pair(m2 + 1, r2));
        } else {
            vec2.push_back(make_pair(l2, r2));
        }
        return check2(vec1, vec2);
    }
}


const int N = 1002;
const LL MOD = 1e9 + 7;
int n, len[N];
LL dp[N][20002];
char str[N][20002];
char t[40005];
vector<pair<int,int> > vec;

bool cmp__(pair<int,int> A, pair<int,int> B) {
    string sa = "", sb = "";
    for (int i = 1; i <= len[A.first]; i ++) {
        if (i == A.second) continue;
        sa += str[A.first][i];
    }
    for (int i = 1; i <= len[B.first]; i ++) {
        if (i == B.second) continue;
        sb += str[B.first][i];
    }
    return sa < sb;
}
int POSITION;
bool cmp(pair<int,int> A, pair<int,int> B) {
    int l1, r1, m1, l2, r2, m2;
    l1 = 0, r1 = len[A.first] - 1; m1 = A.second - 1;
    l2 = 0, r2 = len[B.first] - 1; m2 = B.second - 1;

    if (A.first == POSITION) {
        l1 += len[POSITION - 1] + 1;
        r1 += len[POSITION - 1] + 1;
        if (m1 >= 0) m1 += len[POSITION - 1] + 1;
    }
    if (B.first == POSITION) {
        l2 += len[POSITION - 1] + 1;
        r2 += len[POSITION - 1] + 1;
        if (m2 >= 0) m2 += len[POSITION - 1] + 1;   
    }
    return SA::check1(l1,r1,m1, l2,r2,m2);
}

int main() {
    for(int i=1;i<1<<20;i++) {
        int t = i, c = 0;
        while(t>1) { t/=2; c ++; }
        SA::LG[i] = c;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", str[i] + 1); len[i] = strlen(str[i] + 1);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) { 
       // printf("i = %d\n", i);
        int slen = 0; POSITION = i;
        for (int j = 1; j <= len[i-1]; j ++) t[slen ++] = str[i-1][j];
        t[slen ++] = '#';
        for (int j = 1; j <= len[i]; j ++) t[slen ++] = str[i][j]; t[slen] = '\0';
        SA::init(slen, t);
   // printf("t = %s\n", t);
        vec.clear();
        LL sum = 0;
        for (int j = 0; j <= len[i-1]; j ++) vec.push_back(make_pair(i-1, j));
        for (int j = 0; j <= len[i]; j ++) vec.push_back(make_pair(i, j));
       // printf("%d\n", cmp(make_pair(3,0),make_pair(2,2)));
        //return 0;
        sort(vec.begin(), vec.end(), cmp);


        for (int j = 0; j < vec.size(); j ++) {
           // printf("%d %d", vec[j].first, vec[j].second);
            if (vec[j].first == i-1) {
                sum = (sum + dp[vec[j].first][vec[j].second]) % MOD;
              //  printf("\n");
            } else {
                 dp[vec[j].first][vec[j].second] = sum;
                // printf(" / %lld\n", sum);
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i <= len[n]; i ++) (ans += dp[n][i]) %= MOD;
    cout << ans << endl;
}