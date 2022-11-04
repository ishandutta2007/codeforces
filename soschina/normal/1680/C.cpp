#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
const int N = 2e5 + 2;

int t, n, sum1l[N], sum1r[N];
char s[N];
multiset<int> st;

int main(){
    scanf("%d", &t);
    while(t--){
        st.clear();
        scanf("%s", s + 1);
        n = strlen(s + 1);
        int sum1 = 0, minl = 0x7fffffff, ans = 0x7fffffff;
        for (int i = 1; i <= n; i++)
            if(s[i] == '1')
                sum1++;
        for (int i = 1; i <= n; i++)
            sum1l[i] = sum1l[i - 1] + (s[i] == '1');
        sum1r[n + 1] = 0;
        for (int i = n; i; i--)
            sum1r[i] = sum1r[i + 1] + (s[i] == '1');
        for (int l = 0; l + sum1 <= n; l++){
            int r = l + sum1 + 1;
            minl = min(minl, sum1l[l] - l);
            ans = min(ans, minl + sum1r[r] + r - 1 - sum1);
        }
        st.insert(sum1l[0]);
        for (int i = 1; i <= n + 1; i++){
            ans = min(ans, *st.begin() + sum1r[i]);
            st.insert(sum1l[i]);
            if(i - sum1 >= 0) st.erase(st.find(sum1l[i - sum1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}