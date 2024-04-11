#include <iostream>
using namespace std;

bool coprime(long long a, long long b){
    for(int i=2; i<=50; i++)
        if(a%i == 0 && b%i == 0)
            return false;
    return true;
}

long long L, R;

int main(){
    cin >> L >> R;

    for(long long a=L; a<=R; a++)
        for(long long b=a+1; b<=R; b++)
            for(long long c=b+1; c<=R; c++){
                if(!coprime(a, b)) continue;
                if(!coprime(b, c)) continue;
                if(coprime(a, c)) continue;

                cout << a << " " << b << " " << c << endl;
                return 0;
            }

    cout << -1 << endl;
    return 0;
}