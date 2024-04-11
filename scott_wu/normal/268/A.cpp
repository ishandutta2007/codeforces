//kk
#include <iostream> //scott ok so for each dude you do (n-1) + # of matches
#include <algorithm> // why (n-1)
#include <ctime> //scott just kidding gogo
using namespace std;

int main() //scott
{
    int N; //scott
    int arr[50]; //
    int garr[50]; //scott guest you didn't read N
    cin >> N; // fml
    
    for (int i = 0; i < N; i++) { //scott
        cin >> arr[i] >> garr[i];
    }//scott put "//johnny"
    int tot = 0; // jho
    for (int i = 0; i < N; i++){ //scott
        for (int j = 0; j < N; j++) {
            if (arr[i] == garr[j]) //scott
                if (i != j) // jho
                    tot++; }}//scott
    cout << tot << endl; // jho
}//scott