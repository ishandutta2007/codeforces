#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll d, k;
        cin >> d >> k;
        ll x = 0, y = 0;
        bool second;
        while(true){
            if((x + k) * (x + k) + y * y > d * d){
                second = true;
                break;
            }
            if((x + k) * (x + k) + (y + k) * (y + k) > d * d){
                second = false;
                break;
            }
            x += k;
            y += k;
        }
        if(second){
            cout << "Utkarsh" << endl;
            continue;
        }
        x = k, y = 0;
        bool first;
        while(true){
            if((x + k) * (x + k) + y * y > d * d){
                first = true;
                break;
            }
            if((x + k) * (x + k) + (y + k) * (y + k) > d * d){
                first = false;
                break;
            }
            x += k;
            y += k;
        }
        if(first) cout << "Ashish" << endl;
        else cout << "Utkarsh" << endl;
    }
}