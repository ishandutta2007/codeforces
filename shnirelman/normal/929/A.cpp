#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    int cnt = 0;

    for(int i = 0; i < n-1; i++){

        if(a[i] + k < a[i+1]){

            cout << -1;
            return 0;
        }

        int j = i+1;
        while(j < n && a[i] + k >= a[j])j++;

        if(a[i] + k < a[j]){
            j--;
        }

        cnt++;
        i = j - 1;
        //cout << j << ' ' << cnt << endl;
    }
    cout << cnt;
}