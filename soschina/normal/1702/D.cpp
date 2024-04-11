#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int N = 2e5 + 2;

int t, n, sum, p;
char s[N];
vector<int> vec[26];

struct node{
    int pos;
    char ch;
    node(int pos, char ch) : pos(pos), ch(ch){}
    bool operator<(const node &b) const{
        return pos < b.pos;
    }
};

vector<node> ans;

int main(){
    scanf("%d", &t);
    while(t--){
        ans.clear();
        scanf("%s%d", s + 1, &p);
        n = strlen(s + 1);
        sum = 0;
        for (int i = 0; i < 26; i++)
            vec[i].clear();
        for (int i = 1; i <= n; i++){
            sum += s[i] - 'a' + 1;
            vec[s[i] - 'a'].push_back(i);
        }
        for (int i = 25; i >= 0; i--)
            while(sum > p && vec[i].size()){
                sum -= i + 1;
                vec[i].pop_back();
            }
        for (int i = 0; i < 26; i++)
            for(int pos : vec[i])
                ans.push_back(node(pos, 'a' + i));
        sort(ans.begin(), ans.end());
        for(node nd : ans)
            putchar(nd.ch);
        putchar('\n');
    }
    return 0;
}