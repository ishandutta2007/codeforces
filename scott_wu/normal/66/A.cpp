#include <iostream> //scott so we should read it in as a string
#include <string> //ray, yes ok lets ha
#include <algorithm> //scott wait idea let's just compare it to strings instead of comparing to ints


using namespace std; //ray yeah good idea

string ans[5] = {"byte", "short", "int", "long", "BigInteger"}; //scott negatives might be tricky

string S; //ray yeah  

int main() { //scott
    cin >> S; //ray, wait if you neg just remove neg and subtract 1
    
    string hval[4] = {"127", "32767", "2147483647", "9223372036854775807"}; //scott wait i have a different idea don't do that

    
    if (S[0] == '-') // ray ? you can just kill the negative and subtract 1 and test shit.
    { //scott how to subtract 1
        S[0] += 0; //ray the long way do you have a better idea?
        S = S.substr (1, S.length() - 1); //scott does this work
        S[S.length() - 1] --; //ray wait you need to push ths stuff         
    } //scott wait actually we need --? just start a new if
    if (S[S.length() - 1] > '9') //ray, brace gogo I go
    {//scott we don't need this dude, we need to -- close this loop
    } //ray gogo you carry
    
    if (S[0] == '-') S[S.length() - 1] -= 2; //scott
    S[0]  += 0; //ray, wait we already did S.substr, dude you know that if never happens right?
    
    for (int i = 3; i >= 0; i--) //scott do { gogo
    { // ray
        if (S.length() > hval[i].length() || (S.length() == hval[i].length() && hval[i] < S)) // scott { gogo
        { //ray
            cout << ans[i+1] << "\n"; //scott
        } // ray
        if (S.length() > hval[i].length() || (S.length() == hval[i].length() && hval[i] < S)) // scott { gogo i'm not done
        { // ray
            return 0; //scott
        } // ray
    } //scott
    S[0] += 0; //ray
    cout << ans[0] << "\n"; //scott end now
} // ray submit?