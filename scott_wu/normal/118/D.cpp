//order? scott michael
#include <iostream> //scott k so this is standard dp we dp based on the last chain length (e.g. 5 horsemen and transition goes to 6 horsemen or 1 footman)
using namespace std; // sure, 2 dp arrays, one for last chain feet, one horse?  first index used feet, second used horses, third chain length - 1
int n[2], k[2], dp[210][110][12][2]; //scott, dp is [total used][feet used][chain length][type of chain]
int main() { // chain length or chain length - 1
    cin >> n[0] >> n[1] >> k[0] >> k[1]; //scott uh i think it doesn't matter too much as long as we're consistent so we can do chain len - 1 so now we should initialize all dp to 0? (we can start the initialization after first guy)
    dp[1][0][1][1] = 1; // no need to initialize to 0, global vriables start out that way
    dp[1][0][1][1] = 0; dp[1][0][0][1] = dp[1][1][0][0] = 1; //we're doing chain len - 1 right? <=?
    for (int i = 2; i < n[0] + n[1]; i++) { //sure
    } for (int i = 2; i <= n[0] + n[1]; i++) { //scott we go all the way up to n[0] + n[1] right? we can do the check after entering loop lol
        for (int j = 0; j <= i; j++) { // yeah true
            if (j > n[0] || (i - j) > n[1]) continue; //scott i see what you're doing nvm "k" might be taken?
            for (int l = 0; l <= i; l++) {
                for (int m = 0; m < 2; m++) { //it's k, we'll use [11] to store sum over all chain lengths in this case we need to go back and initialize for dp[1][0][11]aw fuck time to cheat i guess actually let's just comment up to the dp and rewrite it to go forward no need to comment, we can just close the loops :P
                } } } }

    for (int i = 1; i < n[0] + n[1]; i++) { //scott
        for (int j = 0; j <= i; j++) {
            for (int l = 0; l <= 10; l++) { //scott we can check if l is in bounds after choosing m or just not check orite the dp value would be 0 anyway then
                for (int m = 0; m < 2; m++) { // wait we didn't actually add any initialization of the [11]s are we fucked?
                    if (l < k[m] - 1) dp[i+1][j + (m == 0 ? 1 : 0)][l+1][m] = (dp[i+1][j + (m == 0 ? 1 : 0)][l+1][m] + dp[i][j][l][m]) % 100000000; //add same type on   i think we should be ok OOHHH we're doing it forward not backward
                    dp[i+1][j + (m == 0 ? 0 : 1)][0][1-m] = (dp[i+1][j + (m == 0 ? 0 : 1)][0][1-m] + dp[i][j][l][m]) % 100000000; // add other
                    //wait so we might have problems if the other type is already at max # filled no. it won't be in any paths that matter oh gotcha
                    } } } } //scott wait dude we need to account for mod 10^8 i think our soln overflows OK time to cheat i dun wanna redo that done
    int ans = 0; // we need to sum everything
    for (int l = 0; l <= 10; l++) for (int m = 0; m < 2; m++) ans = (ans + dp[n[0]+n[1]][n[0]][l][m]) % 100000000; //scott now we just output don't have printf right
    cout << ans << '\n';
} //scott