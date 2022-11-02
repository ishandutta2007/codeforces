n = gets.to_i

ans = n / 3 * 2
ans += 1 if n % 3 != 0
puts ans