// In the name of God
#include <iostream>
using namespace std;
int arr[100][2];
int main(){
    string h;
    string a;
    cin >> h >> a;
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int t;
        cin >> t;
        char team;
        cin >> team;
        int now = 0;
        if(team == 'a'){
            now = 1;
        }
        int num;
        cin >> num;
        char ver;
        cin >> ver;
        if(ver == 'r')
            arr[num][now] += 2;
        else
            arr[num][now] += 1;
        if(arr[num][now] >= 2){
            arr[num][now] = -999;
            if(now == 0){
                cout << h << " " << num << " " << t << endl;
            }else{
                cout << a << " " << num << " " << t << endl;
            }
        }
    }
    return 0;
}