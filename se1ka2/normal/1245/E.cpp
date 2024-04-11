#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int l[100];
    for(int i = 0; i < 100; i++){
        if((i / 10) % 2 == 0){
            cin >> l[i];
        }
        else{
            cin >> l[(i / 10) * 10 + 9 - i % 10];
        }
    }
    double ans[100] {0};
    double nok[100] {0};
    for(int i = 1; i <= 6; i++){
        ans[i] = 6.0;
    }
    for(int i = 7; i < 100; i++){
        for(int j = 1; j <= 6; j++) ans[i] += (ans[i - j] + 1) / 6.0;
        if(l[i]){
            nok[i] = ans[i];
            int up;
            if(l[i] % 2 == 0) up = i - 10 * l[i];
            else up = ((i - l[i] * 10) / 10) * 10 + 9 - (i % 10);
            if(l[up]) ans[i] = min(ans[i], nok[up]);
            else ans[i] = min(ans[i], ans[up]);
        }
    }
    cout << fixed << setprecision(15) << ans[99] << endl;
}