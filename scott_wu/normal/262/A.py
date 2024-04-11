#http://codeforces.com/problemset/problem/262/A you start

n,k = map(int,input().split())

#print(n)
#print(k)

def lcount(x): #scott is this syntax right
    #print (x)
    if x > 0: #steven
        return lcount (int(x/10)) + (1 if x%10 == 4 or x%10 == 7 else 0)
    else: return 0 #steven recursion everything no loops? :P
inp = []
tot = 0
def solve(x): #main loop for n
    if x < n: #steven go ternary
        global tot
        tot += (1 if lcount(int(inp[x])) <= k else 0)
        solve (x+1) #ok why not put solve(x+1) in the if too?
inp=input().split()
solve(0)
print (tot)#steven





#rte yeah what happened
#might be my silly map nope silly int(input)
#still more bugs
#where are bugs?
#do we have to return?
#i think python lets you return whatever the hell you want still rte
#shit input() reads line not token oh LOL have to do that for the #s also wait there should be some way to read token right?
#idk prolly not? maybe
#did this ac yet nope
#btw ideone gives you compile info
#http://ideone.com/bYnMX2
#this tot thing is screwing us up
#the first 2 nums printed are n,k for debug
#can we pass pointers to ints or references or anything
#oh the problem is tot is global
#global or local?