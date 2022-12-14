//In the name of God
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MaxL = 1e5 + 10;
int arr[MaxL];
vector<int> now;
int main(){
    int L,b,f;
    cin >> L >> b >> f;
    int n;
    cin >> n;
    int cnt = 1;
    for(int q = 0; q < n;q++){
        int c,x;
        cin >> c >> x;
        if(--c){
            for(int j = 0; j <=L;j++)
                if(arr[j] == x)
                    arr[j] = 0;
        }else{
            now.clear();
            for(int i = 0; i <= L;i++){
                if(arr[i])
                    now.push_back(i);
            }
            int st = -1;
            bool flag = 1;
            for(int i = 0; i <= L - x;i++){
                if(st == arr[i]){
                    st = -1;
                    continue;
                }
                if(st != -1)
                    continue;
                if(arr[i]){
                    st = arr[i];
                    continue;
                }
                int p = upper_bound(now.begin(),now.end(),i)-now.begin();
                if(!now.size()){
                    flag = 0;
                    cout << i << endl;
                    arr[i] = cnt;
                    arr[i+x] = cnt;
                    break;
                }
                if(p == 0 && now.size() && now[0] >= i + x + f){
                    flag = 0;
                    cout << i << endl;
                    arr[i] = cnt;
                    arr[i + x] = cnt;
                    break;
                }
                if(p == now.size() && now[p-1] + b > i){
                    continue;
                }
                if(p == now.size()){
                    flag = 0;
                    cout << i << endl;
                    arr[i] = cnt;
                    arr[i+x] = cnt;
                    break;
                }
                if(now[p-1] + b > i || now[p] < i + x + f){
                    continue;
                }
                flag = 0;
                cout << i << endl;
                arr[i] = cnt;
                arr[i+x] = cnt;
                break;
            }
            if(flag){
                cout << -1 << endl;
            }
        }
        cnt++;
    }
}