n = int(input())
ch = input()
popqu = set(ch)
cnt = 0


for b in popqu:
        if ch[0] == b and ch[-1] == b:
            cnt2 = 0
            cnt3 = 0
            for y in ch:
                if y != b:
                    break
                cnt2 += 1
            for y in range(len(ch)-1, -1, -1):
                if ch[y] != b:
                    break
                cnt3 += 1
            cnt += cnt2+cnt3+cnt2*cnt3
        elif ch[0] == b and ch[-1] != b:
            ans = 0
            for y in ch:
                if y != b:
                    break
                ans += 1
            cnt += ans
        elif ch[0] != b and ch[-1] == b:
            ans = 0
            for y in range(len(ch)-1, -1, -1):
                if ch[y] != b:
                    break
                ans += 1
            cnt += ans
print((cnt+1)%998244353)