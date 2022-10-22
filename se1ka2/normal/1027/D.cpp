#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000000;

int a[200005], c[200005];
bool set[200005], looked[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i]--;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<int> v;
        int now = i;
        v.push_back(now);
        while(!set[now] && !looked[now]){
            looked[now] = true;
            now = a[now];
            v.push_back(now);
        }
        v.pop_back();
        if(looked[now]){
            int s = INF;
            while(v.size()){
                int r = v.back();
                v.pop_back();
                s = min(s, c[r]);
                looked[r] = false;
                set[r] = true;
                if(r == now) break;
            }
            ans += s;
        }
        while(v.size()){
            int r = v.back();
            v.pop_back();
            looked[r] = false;
            set[r] = true;
        }
    }
    cout << ans << endl;
}