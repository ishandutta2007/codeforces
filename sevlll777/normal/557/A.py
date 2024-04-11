n = int(input())
mi1, ma1 = map(int, input().split())
mi2, ma2 = map(int, input().split())
mi3, ma3 = map(int, input().split())
if ma1 + mi2 + mi3 >= n:
    print(n - mi2 - mi3, mi2, mi3)
else:
    x = n - ma1 - mi2 - mi3
    if x < (ma2 - mi2):
        print(ma1, mi2 + x, mi3)
    else:
        print(ma1, ma2, n - ma1 - ma2)