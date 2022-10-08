#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<set>
#include<map>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define x first
#define y second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())
#define y0 y0_fedswjfwe
#define pb push_back
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)
int n;
char s1[10000];
char s2[10000];
int main () {
    #ifdef home
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif
    scanf("%d\n", &n);
    gets(s1);
    gets(s2);
    int m1 = strlen(s1);
    int m2 = strlen(s2);
    int c1 = 0;
    int c2 = 0;
//    cerr<<m1<<" "<<m2<<endl;
    int ans1, ans2;
    for (int i = 0; i < n % (m1 * m2); i++) {
        if (s1[i % m1] == s2[i % m2]) {
            continue;
        }
        if (s1[i % m1] == 'R' && s2[i % m2] == 'S') {
            c2++;
        }
        if (s1[i % m1] == 'S' && s2[i % m2] == 'R') {
            c1++;
        }
        if (s1[i % m1] == 'S' && s2[i % m2] == 'P') {
            c2++;
        }
        if (s1[i % m1] == 'P' && s2[i % m2] == 'S') {
            c1++;
        }
        if (s1[i % m1] == 'P' && s2[i % m2] == 'R') {
            c2++;
        }
        if (s1[i % m1] == 'R' && s2[i % m2] == 'P') {
            c1++;
        }
    }
    
    ans1 = c1;
    ans2 = c2;
    c1 = 0;
    c2 = 0;
    for (int i = 0; i < m1 * m2; i++) {
        if (s1[i % m1] == s2[i % m2]) {
            continue;
        }
        if (s1[i % m1] == 'R' && s2[i % m2] == 'S') {
            c2++;
        }
        if (s1[i % m1] == 'S' && s2[i % m2] == 'R') {
            c1++;
        }
        if (s1[i % m1] == 'S' && s2[i % m2] == 'P') {
            c2++;
        }
        if (s1[i % m1] == 'P' && s2[i % m2] == 'S') {
            c1++;
        }
        if (s1[i % m1] == 'P' && s2[i % m2] == 'R') {
            c2++;
        }
        if (s1[i % m1] == 'R' && s2[i % m2] == 'P') {
            c1++;
        }
    }
    ans1 += c1 * (n / (m1 * m2));
    ans2 += c2 * (n / (m1 * m2));
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}