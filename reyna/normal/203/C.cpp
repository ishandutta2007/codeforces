#include <iostream>
#include <algorithm>
using namespace std;
pair<int,int> arr[100001];
int main(){
    int n,d,a,b;
    cin >> n >> d >> a >> b;
    for(int i = 0; i < n;i++){
        int c,d;
        cin >> c >> d;
        arr[i].first = c*a+d*b;
        arr[i].second = i+1;
    }
    sort(arr,arr+n);
    long long counter = 0;
    int in = n;
    for(int i = 0; i < n;i++){
        counter+=arr[i].first;
        if(counter > d){
            in = i;
            break;
        }
    }
    cout << in << endl;
    for(int i = 0; i < in;i++){
        cout << arr[i].second << " ";
    }
    cout << endl;
    return 0;
}