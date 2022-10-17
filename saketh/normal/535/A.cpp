#include <iostream>
using namespace std;

int N;

string small[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string tens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main(){
    cin >> N;
    
    if(N >= 20){
        cout << tens[N/10];
        if(N%10) cout << "-" << small[N%10];
        cout << endl;
    }
    else cout << small[N] << endl;
}