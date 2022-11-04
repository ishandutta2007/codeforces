#include <cstdio>
#include <set>
#include <map>
using namespace std;

int q;
char c;
long long x;
set<long long> st;
map<long long, int> mp;

int main(){
	scanf("%d", &q);
    while(q--){
        scanf(" %c%lld\n", &c, &x);
        switch(c){
            case '+':
                st.insert(x);
                break;
            case '?':
                while(st.find((mp[x] + 1) * x) != st.end())
                    mp[x]++;
                printf("%lld\n", (mp[x] + 1) * x);
        }
    }
	return 0;
}