#scott http://codeforces.com/problemset/problem/291/A now? ok you start

n = int(input())
arr = map (int, input().split()) #scott

#for i in arr:
#    print (i)

cnt = 0 
clast, llast = -1, -1 #scott wait we need to sort

arr = sorted(arr)

bad = False #scott so now we just count # of pairs and make sure there's not 3 in a row right?ok
#so a neat thing you can do is just for x in arr
for i in arr:
    #print (i)
    if i > 0: #scott so last was the last one, llast was the second last one
        if i == clast :
            cnt += 1 #scott
            if clast == llast :
                bad = True #scott your turn
        llast = clast
        clast = i #scott
if bad == False:
    print (cnt) #scott
else:
    print (-1) #scott

#darn ii'm getting RTE test 1