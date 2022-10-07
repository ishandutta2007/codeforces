#include <complex> //steven is a ho
#include <iostream> //scott so can we just test for each 2-adic valuation? like bin search
#include <cstdio> //steven i haven't solved it yet
#include <algorithm> //scott so there's at most one solution for each 2-adic valuation, you bin search to find that soln if it exists, 2-adic valuation is gonna beat most like 60


using namespace std; //steven, let me think first, it wants all possible solutions.
typedef long long ll; //scott right so you test all 2-adic valuations

ll choose2(ll x) { //steven
	return (x * (x - 1)) / 2; //scott do you agree?
} //steven, what's 2-adic binary?

int main() //scott oh sorry, largest power of 2 dividing x where x is # of people so we just try all possibilities from 0 to 60
{ //steven, ah i misread.
	ll N; //scott ok so this works right?
    cin >> N; //steven, probably if you say so, i need to finish thinking

	ll ans[110]; int nans = 0; //scott forgot vector lol
    //for(int i = 1; true; ++i) { //steven we can use division (x - ic2)/(i) must be ()2^k-1), don't have to binsearch.
//	}//scott we start at 0 right? wait i don't understand what you mean
    
   // for(int i = 1; true; ++i) { //i is the final odd number you get, you play (i C 2) games, you're right how do you generate odds
//	}//scott too slow then? like you need to loop on what the highest power of 2 is
    for(int i = 0; i < 61; ++i) { //steven i see i know
		ll lo = 0, hi = min (1e9, 1e18 / (1LL << i)); //scott so the value is going to be like (2*mid+1) * (1<<i)
        while (lo < hi) { //steven
        	ll mid = (lo + hi) / 2; //scott do manly binary search so we don't need to actually factor in 1<<i yeah wait make sure you're using 2*mid+1
            mid -= mid & 1; //steven wait is there a tricky way to binsearch on odds
			mid = 2 * ((lo + hi) / 2) + 1; //scott yeah you use 2*mid + 1 as your actual value that's why i made hi = 1e18 / 1<<i
            ll val = mid; //steven my computation is different from yours where did your mid choose 2 go
			
			//scott no the point is that the value we're testing as x is 2*mid + 1, we binary search to figure out which lo creates the right 2*lo+1, that's how we binsearch on odds
            // no we need mid choose 2 cause that's how many games you play right
            //scott yes i haven't done any of that, i've just set mid equal to the x we're testing you already declared ll val
            val = mid * ((mid - 1) / 2 + (1LL << i) - 1); //steven, is this what you have wait no no i = 0 needs to be
            
            if (N <= val) hi = mid / 2; else lo = mid / 2 + 1; //scott i don't understand your val line, i'm just gonna assume you haev it right
            int ok; //steven, should be good now, oh you made binsearch manly good, my val line is probably wrong.
            
            } //scott now we check lo to see if == N
        ll mid = lo * 2 + 1; //steven, if this passes i'm gonna drink some coke or something.
            //scott wait i don't understand, if i != 0 you haev 1<<i - 2? yeah that's what i thought
            //i should've just done like 2 * ((1LL<<i)-1), but it's cause shit shit it was right before i'm dumb
            //thought n people -> n games played :( i cheated
            
            if (N == (mid * ((mid - 1) / 2 + (1LL << i) - 1))) //scott yeah but only cause you made two comment lines in a row
            int iwasafk;//steven sorry
			if (N == (mid * ((mid - 1) / 2 + (1LL << i) - 1))) //scott yeah but only cause you made two comment lines in a row
                ans[(++nans)-1] = mid; //steven
			if (N == (mid * ((mid - 1) / 2 + (1LL << i) - 1))) //scott mid is not the actual value remember
                ans[nans-1]<<=i; //steven, i don't even know what i'm doing anymore
        } //scott ok now we output rite make sure to check -1
        sort(ans,ans+nans); //steven right        
        if (nans == 0) { cout << "-1\n"; return 0;} //scott looks good
        else for(int i = 0; i < nans; ++i) {//steven
                cout << ans[i] << "\n";} //scott
        //system("Pause"); //steven
    return 0; //scott
}//steven

//tle rofl