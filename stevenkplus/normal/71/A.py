# http://codeforces.com/problemset/problem/71/A
# you start

n = int(input()) #scott

for t in range(n): #steven
    s = input() #scott
    l = len(s) #steven, idk if i can do this
    if l > 10: #scott
        s = s[0:1] + str(l - 2) + s[l-1:]
    print (s) #scott ??
#steven afk sry