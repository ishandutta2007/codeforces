# http://codeforces.com/problemset/problem/313/A
n = int(input()) #steven

if n >= 0: print(n) #scott
else:
    best = n #steven my bad, just use string to remove last, second last lol, it's not for loop. it's second last or last.
    s = str(n)
    best = max(best, int(s[:-1]), int(s[:-2]+s[-1])) #steven, qed.
    print (best) #wait you can do that?