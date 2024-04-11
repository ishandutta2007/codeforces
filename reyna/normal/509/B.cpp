//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 123;
int p[Maxn];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n;i++)
        cin >> p[i];
    int Min = Maxn;
    int Max = 1;
    for(int i = 0; i < n;i++){
        Min = min(Min,p[i]);
        Max = max(Max,p[i]);
    }
    if(Max - Min > k){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < Min;j++){
            cout << 1 << ' ';
        }
        for(int j = Min; j < p[i];j++){
            cout << j - Min + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}