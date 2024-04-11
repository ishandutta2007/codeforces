n = int(input())
card = [[int(s) for s in raw_input().split()][1:] for x in range (n)]

for i in range(n):
    for j in range(n):
        if j != i:
            for k in card[j]:
                if k not in card[i]:
                	break
            else:
                print "NO"
                break
    else:
        print "YES"