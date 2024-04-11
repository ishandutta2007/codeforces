#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 2e5 + 1;

int t, p;
char s[N];
bool vis[256], flag, ans;
vector<char> vec;

int main(){
    scanf("%d", &t);
    while(t--){
        memset(vis, 0, sizeof(vis));
        p = 0;
        ans = true;
        vec.clear();
        flag = false;
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; i++){
            if(flag){
                if(vec[p] == s[i]){
                    p = ++p % vec.size();
                }else{
                    ans = false;
                }
            }else{
                if(vis[s[i]]){
                    flag = true;
                    if(s[i] == vec[0]){
                        p = ++p % vec.size();
                    }else{
                        ans = false;
                    }
                }else{
                    vis[s[i]] = true;
                    vec.push_back(s[i]);
                }
            }
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}