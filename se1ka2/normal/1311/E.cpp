#include <iostream>
using namespace std;

int main()
{
    int p[20];
    p[0] = 1;
    for(int i = 1; i < 20; i++) p[i] = p[i - 1] * 2;
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, d;
        cin >> n >> d;
        int b[5005];
        int s = 0;
        for(int i = 0; i < n; i++){
            b[i] = 1;
            s += i;
        }
        if(s < d){
            cout << "NO" << endl;
            continue;
        }
        int l = 1;
        for(int i = n - 1; i >= 0; i--){
            if(s - d <= i - l){
                b[i]--;
                b[i - (s - d)]++;
                s = d;
                break;
            }
            if(i == l){
                break;
            }
            b[i]--;
            b[l]++;
            s = s - i + l;
            if(b[l] == p[l]) l++;
        }
        if(s > d){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int r = 1;
        for(int i = 1; i < n; i++){
            int x = r;
            for(int j = 0; j < b[i]; j++){
                printf("%d ", x);
                if(j % 2) x++;
            }
            r += b[i - 1];
        }
        cout << endl;
    }
}