#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    int a[200005];
    int b[200005] {0};
    int last = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(mp[a[i]] == 0){
            mp[a[i]] = i + 1;
            b[i + 1] = a[i];
        }
        if((int)mp.size() > k){
            while(true){
                if(b[last]){
                    mp.erase(b[last]);
                    last++;
                    break;
                }
                last++;
            }
        }
    }
    cout << (int)mp.size() << endl;
    for(int i = n; i >= last; i--) if(b[i]) cout << b[i] << " ";
    cout << endl;
}