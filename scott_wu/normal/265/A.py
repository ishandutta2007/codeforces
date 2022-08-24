#scott http://codeforces.com/problemset/problem/265/A new problem

RO = input() # darn i don't know how to read string
ins = input() #scott
n = 0


for x in range (len(ins)): #scott yeah that looks fine
    #print (x)
    if ins[x] == RO[n]:
        n += 1 #scott

print (n+1)