#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2002;
int len;
char s1[N], s2[N];
vector<char> tmp;
vector<int> ans;
void solve(int p1, int p2) {
    if (p1+p2 < len) ans.push_back(p1+p2);
    if (len-p2 < len) ans.push_back(len-p2);
    if (len-p1-1 < len) ans.push_back(len-p1-1);

    tmp.clear();
    for (int i = p1; i >= 1; i --) tmp.push_back(s1[i]);
    tmp.push_back(s1[p1+p2+1]);
    for (int i = p1+p2; i>=p1+1; i --) tmp.push_back(s1[i]);
    for (int i = len; i >= p1+p2+2; i --) tmp.push_back(s1[i]);
    for (int i = 0; i < tmp.size(); i ++) s1[i+1] = tmp[i];  
}
bool check() {
    vector<char> v1, v2;
    for (int i = 1; i <= len; i ++) v1.push_back(s1[i]);
    for (int i = 1; i <= len; i ++) v2.push_back(s2[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return v1 == v2;
}
int main() {
    scanf("%d %s %s", &len, s1+1, s2+1);   
    if (!check()) {
        printf("-1\n");
        return 0;
    }
    int l = len / 2, r = len / 2;
    vector<char> shift;
    for (int i = 1; i <= len; i ++) {
        if (i % 2) 
            shift.push_back(s2[l --]);
        else
            shift.push_back(s2[++ r]);
    }
    for (int i = 0; i < ((len%2==0)?len:(len-1)); i ++) {
       int posx = -1;
       for (int j = i+1; j <= len; j ++) {
            if (s1[j] == shift[i]) {
                posx = j;
                break;
            }
       }
       solve(i, posx-i-1);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", len-ans[i]);
    }
}