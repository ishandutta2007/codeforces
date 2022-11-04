#include <cstdio>
#include <set>
using namespace std;
const int N = 2e5 + 1;

int t, n, k, a[N];
long long sum;

set<int> st;

int main(){
    scanf("%d", &t);
    while(t--){
        st.clear();
        sum = 0;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            st.insert(a[i]);
        }
        bool flag = false;
        for(int i = 1; i <= n; i++){
            if(st.find(a[i] - k) != st.end()) flag = true;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}