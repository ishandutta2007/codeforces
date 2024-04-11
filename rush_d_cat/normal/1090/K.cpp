#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 1000000+10;
int n;
char s[N],t[N];
map< pair<string, set<int> >, vector<int> > mp;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s%s",s,t);

        set<int> st; st.clear(); string str="";
        for(int j=0;t[j];j++){
            st.insert(t[j]-'a');
        }
        int pos=-1;
        for(int j=0;s[j];j++){
            if(!st.count(s[j]-'a')) pos=j;
        }
        for(int j=0;j<=pos;j++){
            str+=s[j];
        }
        /*
        cout << "!" << i << endl;
        cout << str << endl;
        for(auto x: st) cout << x << endl;
        */
        mp[make_pair(str,st)].push_back(i);
    }
    printf("%d\n", mp.size());
    for(auto p: mp) {
        printf("%d", p.second.size());
        for(auto x: p.second) {
            printf(" %d", x);
        } printf("\n");
    }
}