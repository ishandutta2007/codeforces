#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    string hi;
    cin >> hi;

    int count = 0;
    for(int i=0; i<hi.length(); i++){
        if(hi[i] == 'a' || hi[i] == 'e' || hi[i] == 'i' || hi[i] == 'o' || hi[i] == 'u' || hi[i] == '1' || hi[i] == '3' || hi[i] == '5' || hi[i] == '7' || hi[i] == '9'){
            count++;
        }
    }

    cout << count;

    return 0;
}