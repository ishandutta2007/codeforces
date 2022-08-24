h, m = map (int, raw_input().split(':'))

def is_p():
    return 1 if (h % 10 == m / 10) and (m % 10 == h / 10) else 0

ans = 0
while is_p() == 0:
    m += 1
    if m == 60:
        h += 1
        m = 0
    if h == 24:
        h = 0
    ans += 1
print ans