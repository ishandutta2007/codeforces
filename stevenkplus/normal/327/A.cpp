#include <cstdio> //steven btw, rules are we don't edit lines we already finished are you there?

int main(int argc, char ** argv)
{    int n; //steven go fast! we don't need any arrays don't worry also i'm not sure about the case where it's all 1s 
scanf("%d\n", &n); // raphael
int bst = -1, cnt = 0, ans = 0; //steven

for (int i = 0; i < n; i++) { //raphael
    int nxt; scanf("%d", &nxt); //steven type one line only :P that includes {} btw for all 1s i think ans = n. do it however you want to i'll just follow along my way probably won't work anyway hell we could even n^3 this if we had an array oops we're just finding the range with maximal #0s - #1s. yeah the amount the sum increases by if we flip that range we can use argc if we need another int
    argc = nxt;
    if (nxt == 0) ++cnt; else --cnt,++ans; //steven if cnt is negative cnt = 0 i guess, we can store #1s in bst
    if (nxt == 1) ++bst; else --bst; //raphael
    if (nxt == 0) ++bst; //steven could've done bst += nxt   bst will be total #1s. so now we do if (cnt < 0) cnt = 0
    
    bst -= nxt; //steven we'll make bst the max #1s gained, so max cnt ever reaches, you can get from flipping a range hehe yeah it's just cnt, that's why cnt < 0 cnt = 0, it makes the starting position optimal
    if (cnt > bst) bst = cnt; //raphael
    if (cnt < 0) cnt = 0; //raphael ans is number of ones and bst is number of ones but ans is getting added when nxt = 1

}//steven ans is #1s, bst is #1s you gain, print ans+bst

printf("%d\n", ans + bst); //raphael
return 0; } //steven



//http://codeforces.com/contest/327/submission/4084200 lul we got it wrong the stupid all 1s thing is supposed to be n - 1, not n cause apparently you must flip some range.

//so i just moved if(cnt < 0) cnt = 0 to under cnt>bst and it should be right now. i blame it on the problem statement