#!/usr/bin/env ruby

def pow(a, b, m)
  return (b == 0 ? 1 : pow(a * a % m, b / 2, m) * (b % 2 == 0 ? 1 : a)) % m
end

P = 1000000007
M = 2345678917
n, m = gets.split.map(&:to_i)

if m == 1
  puts n
  exit
end

a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)

da = a.drop(1).zip(a[0..-2]).map{|a, b| a - b}
hb = b.drop(1).zip(b[0..-2]).map{|a, b| a - b}.inject{|a, x| (a * P + x) % M} 

n -= 1
m -= 1
MP = pow(P, m, M)

ans = 0
ha = 0
da.each_with_index do |x, i|
  ha = (ha * P + x) % M
  ha = (ha - da[i - m] * MP) % M if i >= m
  ans += 1 if i >= m - 1 && ha == hb
end

puts ans