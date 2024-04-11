#include <bits/stdc++.h>

using namespace std;

bool arr[(int)9e5 + 3];
int arr2[(int)9e5 + 3];

int main()
{
    int q, x, tp, s = 0;
    cin >> q >> x;
    for(int i = 0; i < q; i++){
        cin >> tp;
        if(tp%x == s){
            arr[s] = 1;
            tp %= x;
            while(arr[s] && s < q){
                s++;
            }
            arr2[tp%x] =  x+tp%x;
        } else {
            if(arr2[tp%x] == 0) arr2[tp%x] = tp%x;
            arr[arr2[tp%x]] = 1;
            if(arr2[tp%x] < q){
                arr2[tp%x] += x;
            }
            while(arr[s]) s++;
        }
        cout << s << endl;
    }
    return 0;
}