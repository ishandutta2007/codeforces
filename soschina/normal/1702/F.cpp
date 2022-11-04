#include <cstdio>
#include <set>
using namespace std;

int t, n, x;
multiset<int> st;

int main(){
	scanf("%d", &t);
    while(t--){
        st.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &x);
            while((x & 1) == 0)
                x >>= 1;
            st.insert(x);
        }
        for (int i = 1; i <= n; i++){
            scanf("%d", &x);
            while(x && st.find(x) == st.end())
                x >>= 1;
            if(x)
                st.erase(st.find(x));
        }
        puts(st.empty() ? "YES" : "NO");
    }
	return 0;
}