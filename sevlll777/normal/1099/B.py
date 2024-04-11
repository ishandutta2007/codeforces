n = int(input())
t = 0
while 1:
    t += 1
    if (t//2)*(t-t//2) >= n:
        print(t)
        break