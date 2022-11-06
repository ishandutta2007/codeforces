n = int(raw_input())
if n < 3:
    print(-1)
else:
    s = "3 2 1"
    for i in range(4, n+1):
        s +=  " " + str(i)
    print(s)