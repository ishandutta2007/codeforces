#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n;
const int inf = 27; 
string str[102];
map<string, int> mp;
vector<int> v[10002], ans;
int deg[102], vis[102], link[102][102];
int ok = 1;

int main() {
    cin >> n;
    int cnt = 1; mp[""] = 1;

    for(int i=1;i<=n;i++) {
        cin >> str[i];
        int len = str[i].length();
      
        string tmp = ""; 
        v[mp[tmp]].push_back(str[i][0] - 'a' + 1);
   
        for(int j=0;j<len;j++) {
            tmp += str[i][j];

            if(mp[tmp] == 0) {
                mp[tmp] = ++ cnt;
            }

            if(j+1<len) {
                v[mp[tmp]].push_back(str[i][j+1] - 'a' + 1);
            }

            if(j+1==len)
                v[mp[tmp]].push_back(inf);
        }   
    }

    for(int i=1;i<=cnt;i++) {

        for(int j=0;j<(int)v[i].size()-1;j++) {
            if(v[i][j] != v[i][j+1]) { 
                if(link[ v[i][j] ][ v[i][j+1] ] == 0) deg[ v[i][j+1] ] ++;
                link[ v[i][j] ][ v[i][j+1] ] = 1;
            }
        
        }
    }

    for(int t=1;t<=100;t++) {
        for(int i=1;i<=27;i++) {
            //cout << deg[1] << endl;
            if(deg[i] == 0 && vis[i] == 0) {
                for(int j=1;j<=27;j++) {
                    if(link[i][j]) {
                        deg[j] --;
                    }
                }
                //printf("%d", i);
                //cout << (char)(i + 'a' - 1); 
                ans.push_back(i); vis[i] = 1;
                break;
            }
        }
    }
    //printf("\n");

    if(ans.size() != 27) ok = 0;
    //cout << ans.size() << endl;
    for(int i=1;i<=26;i++) {
        if(link[i][27]) ok = 0;
    }

    if(!ok) {
        printf("Impossible\n");
        return 0;
    }

    for(int i=0;i<ans.size();i++) {
        if(ans[i] != 27) {
            printf("%c", (char)('a' + ans[i] - 1));
        }
    }

    printf("\n");

}