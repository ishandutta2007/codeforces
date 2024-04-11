#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 1;

int t, n, x, y;
vector<int> vec[N];
bool flag;

int main(){
    scanf("%d", &t);
    while(t--){
        flag = true;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            vec[i].clear();
        for (int i = 1; i <= n; i++){
            scanf("%d%d", &x, &y);
            if(x == y)
                flag = false;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        for (int i = 1; i <= n && flag; i++){
            if(vec[i].size() != 2)
                flag = false;
            if(vec[i][0] == vec[i][1])
                vec[i].clear();
        }
        for (int i = 1; i <= n && flag; i++)
            if(vec[i].size()){
                x = y = i;
                do{
                    int xx = vec[x].back();
                    vec[x].pop_back();
                    for (int i = 0; i < vec[xx].size(); i++)
                        if(vec[xx][i] == x)
                            vec[xx].erase(vec[xx].begin() + i);
                    int yy = vec[y].back();
                    vec[y].pop_back();
                    for (int i = 0; i < vec[yy].size(); i++)
                        if(vec[yy][i] == y)
                            vec[yy].erase(vec[yy].begin() + i);
                    x = xx;
                    y = yy;
                } while (x != y && vec[x].size() && vec[y].size() && vec[x][0] != y);
                if(x != y)
                    flag = false;
            }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}